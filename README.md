# TestEigenjs
使用eigen进行矩阵运算测试
### 下载Eigen,http://eigen.tuxfamily.org

```
wget http://bitbucket.org/eigen/eigen/get/3.3.4.tar.gz
tar xvf 3.3.4.tar.gz
```

### 编译

```
emcc -I ../eigen/ main.cpp -o main.js -s EXPORTED_FUNCTIONS="['_printMatrixXd','_addMatrixXd','_subMatrixXd','_trMatrixXd','_muiltMatrixXd','_inverseMatrixXd','_adjointMatrixXd','_traceMatrixXd','_detMatrixXd','_rankMatrixXd']"  -s WASM=1
```

### [测试访问](https://zhhaogen.github.io/TestEigenjs/)