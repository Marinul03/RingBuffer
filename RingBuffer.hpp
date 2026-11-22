#include <array>
#include <cstddef>
#include <optional>
class RingBuffer{
private:
	std::array<int, cap> data{};
	std::size_t head=0;
	std::size_t tail=0;
	std::size_t count=0;
public:
	static constexpr std::size_t cap=8; //fixed-size int
	bool push(int val){
		if (full()){
			return false;
		}
		data[tail]=val;
		tail=(tail+1)%cap;
		++count;
		return true;
	}
	std::optional <int> pop(){
		if(empty()){
			return std::nullopt;
		}
		int value = data[head];
		head=(head+1)%cap;
		--count;
		return val;
	}
	std::size_t size() const noexcept {return count;}
	bool empty() const noexcept {return count==0;}
	bool full() const noexcept {return count==cap;}
}
