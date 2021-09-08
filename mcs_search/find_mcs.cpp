#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <iostream>
#include <GraphMol/RDKitBase.h>
#include <GraphMol/FileParsers/FileParsers.h>  //MOL single molecule !
#include <GraphMol/FileParsers/MolSupplier.h>  //SDF
#include <GraphMol/FMCS/FMCS.h>
#include <GraphMol/FileParsers/MolSupplier.h>

using namespace RDKit;

void get_mcs(std::string pathName, unsigned int maxToDo,
              std::vector<ROMOL_SPTR> &mols) {
  RDKit::SDMolSupplier suppl(pathName, true, true, true);
  unsigned int nDone = 0;
  while (!suppl.atEnd() && (maxToDo <= 0 || nDone < maxToDo)) {
    RDKit::ROMol *m = suppl.next();
    if (!m) {
      continue;
    }
    m->updatePropertyCache();
    // the tautomer hash code uses conjugation info
    MolOps::setConjugation(*m);
    nDone += 1;
    mols.push_back(ROMOL_SPTR((ROMol *)m));
  }
  std::cerr << "read: " << nDone << " mols." << std::endl;
  MCSParameters p;
  MCSResult res = findMCS(mols, &p);
  std::cout << "\n"
                << "MCS: " << res.SmartsString << " " << res.NumAtoms
                << " atoms, " << res.NumBonds << " bonds\n";

}


int main(int argc, char *argv[]) {
  std::vector<ROMOL_SPTR> mols;
  if (argc==3) {
  get_mcs(argv[1], 10000, mols, argv[2]);
  }
  else {get_mcs(argv[1], 10000, mols);}
}

