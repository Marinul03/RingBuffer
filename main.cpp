#include <iostream>
#include "RingBuffer.hpp"
int main() 
{
	RingBuffer<int, 5> rb;
	for(int i=0; i < RingBuffer::N; i++)//fills buffer
		rb.push(i);
	std::cout<<"size= "<<rb.size()<<std::endl<<"Full? "<<std::boolalpha<<rb.full()<<'\n';
	bool ok=rb.push(9);
	std::cout<<(ok ? "ok":"FULL")<<'\n';//tries to push() 9; supposed to return FULL
	for(int i=0;i<3;++i)
	{
		if (auto v=rb.pop())
			std::cout<<"pop("<<i<<")"<<*v<<'\n';
	}//pops some values
	rb.push(11);
	rb.push(22);
	while(auto v=rb.pop())
		std::cout<<"pop("<<i<<")"<<*v<<'\n';//pops all values
	std::cout<<"empty? "<<rb.empty();//checks if empty
}
