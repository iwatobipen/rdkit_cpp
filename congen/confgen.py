import sys
from rdkit import Chem
from rdkit.Chem import AllChem

def gen_conf(inputfile, outputfile):
    mols = [m for m in Chem.SmilesMolSupplier(inputfile, "\t", 0, 1, False) if m != None]
    w = Chem.SDWriter(outputfile)
    for mol in mols:
        hmol = Chem.AddHs(mol)
        res = AllChem.EmbedMultipleConfs(hmol, 10, 0)
        AllChem.MMFFOptimizeMoleculeConfs(hmol, 0, 2000)
        for i in res:
            hmol.SetProp("confId", f"{i}")
            w.write(hmol, confId=i)

if __name__=="__main__":
    gen_conf(sys.argv[1], sys.argv[2])