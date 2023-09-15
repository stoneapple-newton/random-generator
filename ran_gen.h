#ifndef RAN_GEN_H
#define RAN_GEN_H
#include<time.h>
//Xorshift 64 change(to uint64_t)
void __xorshift64_chg(uint64_t &val){
	val ^= val << 13;
	val ^= val >> 7;
	val ^= val << 17;
}
//class to handle random numbers.
class ran_gen_c{
private:
	//private random values.
	uint16_t rand16v;
	uint32_t rand32v;
	uint64_t rand64v;
public:
	//some random stuff
	ran_gen_c(){
		uint64_t tval = (clock() << 1) + 1;//clock value
		tval += (tval << 32) + (tval >> 32);
		rand64v = tval;
		rand32v = tval & 0xffffffff;
		rand16v = tval & 0xffff;
	}
	void srand(){
		this -> operator=(ran_gen_c());
	}
	void __xorshift64(){
		__xorshift64_chg((*this).rand64v);
		rand32v = ((*this).rand64v >> 32) + ((rand16v >> 16) & 0xffffffff);
		rand16v = ((*this).rand32v >> 16) + ((rand16v >> 8) & 0xffff);
	}
	//integer random
	uint16_t rand16(){
		this -> __xorshift64();
		return (*this).rand16v;
	}
	uint32_t rand32(){
		this -> __xorshift64();
		return (*this).rand32v;
	}
	uint64_t rand64(){
		this -> __xorshift64();
		return (*this).rand64v;
	}
	//floating-point values
	float randf32() {
		return static_cast<float>(rand64()) / static_cast<float>(UINT64_MAX);
	}

	double randf64() {
		return static_cast<double>(rand64()) / static_cast<double>(UINT64_MAX);
	}

};
#endif