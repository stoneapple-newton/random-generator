# random-generator
this repository is a C++ light-weight random library.
# version and size
version: v1.0
size: 1372 bytes

## How to use
1.install this `ran_gen.h` file.
2.write `ran_gen_c ran_gen;`.
3.initalize `ran_gen`.`ran_gen.srand();`
4.use it.e.g.
`ran_gen.rand16()`
`ran_gen.rand32()`
`ran_gen.rand64()`
`ran_gen.randf32()`
`ran_gen.randf64()`
```cpp
#include<iostream>
#include<ran_gen.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ran_gen_c gen;
    gen.srand();
    cout << gen.rand32();
	return 0;
}
```
