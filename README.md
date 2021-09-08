# rdkit_cpp

## build find_mcs

- build find_mcs with following command.

```
$ cd mcs_search
$ mkdir build
$ cd build
$ cmake ..
$ make find_mcs
```

- after compling the code, find_mcs will be generated.

## how to use find_mcs

- type following command
```
#$ find_mcs <your sdf>
$ find_mcs cdk2.sdf
# or add threshold
#$ find_mcs <your_sdf> <threshold:float>
$ find_mcs cdk2.sdf 0.7
```


## 
