import sys
from rdkit import Chem
from rdkit.Chem import rdFMCS

def get_mcs(mols):
    mcs = rdFMCS.FindMCS(mols)
    return mcs

if __name__=='__main__':
    mols = Chem.SDMolSupplier(sys.argv[1])
    mcs = get_mcs(mols)
    print(mcs.smartsString)
