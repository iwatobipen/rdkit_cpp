//
// Working with 3D molecules - example11.cpp

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <Geometry/point.h>
#include <GraphMol/GraphMol.h>
#include <GraphMol/MolOps.h>
#include <GraphMol/MolAlign/AlignMolecules.h>
#include <GraphMol/DistGeomHelpers/Embedder.h>
#include <GraphMol/ForceFieldHelpers/MMFF/MMFF.h>
#include <GraphMol/ForceFieldHelpers/UFF/UFF.h>
#include <GraphMol/SmilesParse/SmilesParse.h>
#include <GraphMol/FileParsers/MolWriters.h>
#include <GraphMol/FileParsers/MolSupplier.h>
using namespace RDKit;

void gen_conf(std::string pathName,
              std::string outName, 
              std::vector<ROMOL_SPTR> &mols) {
  RDKit::SDMolSupplier suppl(pathName, true, true, true);
  bool takeOwnership = true;
  boost::shared_ptr<RDKit::SDWriter> sdf_writer( new RDKit::SDWriter( outName ) );
  
  unsigned int nDone = 0;
  while (!suppl.atEnd()) {
    RDKit::ROMol *m = suppl.next();
    if (!m) {
      continue;
    }
    m->updatePropertyCache();
    // the tautomer hash code uses conjugation info
    MolOps::setConjugation(*m);
    //RDKit::DGeomHelpers::EmbedMolecule(*m, 0, 1234, useExpTorsionAnglePrefs=true);
    RDKit::DGeomHelpers::EmbedMolecule(*m, 0, 1234);
    RDKit::MMFF::MMFFOptimizeMolecule(*m, 2000, "MMFF94s");
    sdf_writer->write(*m);
    nDone += 1;

  }
}
int main(int argc, char *argv[]) {
  std::vector<ROMOL_SPTR> mols;
  gen_conf(argv[1], argv[2], mols);
  }
  