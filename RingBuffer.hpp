#include <array>
#include <cstddef>
#include <optional>
#include <utility>
template <typename T, std::size_t N>
class RingBuffer{
private:
	void adv_tail(){
		tail=(tail+1)%N;
		++count;
	}
	std::array<T, N> data{};
	std::size_t head=0;
	std::size_t tail=0;
	std::size_t count=0;
public:
	bool push(const T& val){
		if (full()){
			return false;
		}
		data[tail]=val;
		adv_tail();
		return true;
	}
	std::optional <T> pop(){
		if(empty()){
			return std::nullopt;
		}
		std::optional<T> val{std::move(data[head])};
		head=(head+1)%N;
		--count;
		return val;
	}
	constexpr std::size_t size() const noexcept {return count;}
	constexpr bool empty() const noexcept {return count==0;}
	constexpr bool full() const noexcept {return count==N;}
	static constexpr std::size_t capacity() {return N}
}
