#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t 이런걸 외워둬야한다고 말씀을 하시는 교수님
#include <stdio.h> // for printf

void dump(void* p, size_t n) {
	uint8_t* u8 = static_cast<uint8_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%02X ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}

uint16_t my_ntohs(uint16_t n) {
	uint16_t upper_byte = n & 0xFF00; //0x3400
	upper_byte = n >> 8; //0x34
	uint16_t lower_byte = n & 0x00FF; //0x12
	lower_byte = n << 8; //0x1200
	uint16_t return_byte = lower_byte | upper_byte;
	return return_byte;
}

uint32_t my_ntohl(uint32_t n) {
	uint32_t first = (n & 0xff000000) >> 24;
	uint32_t second = (n & 0x00ff0000) >> 8;
	uint32_t third = (n & 0x0000ff00) << 8;
	uint32_t fourth = (n & 0x000000ff) << 24;
	uint32_t return_byte = first | second | third | fourth;
	return return_byte;
}

void write_4660() {
	uint16_t port = 4660; // 0x1234
	printf("port number = %d\n", port);
	dump(&port, sizeof(port));
}

void  write_0x1234() {
	uint8_t network_buffer[] = { 0x12, 0x34 };
	uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
	uint16_t n = my_ntohs(*p); // TODO 이 함수를 만들고, 두 바이트짜리 앞뒤를 뒤집어주어야함
	printf("16 bit number=0x%x\n", n);
}

void  write_0x12345678() {
	uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	uint32_t n = my_ntohl(*p); // TODO
	printf("32 bit number=0x%x\n", n);
}

int main() {
	write_4660();
	write_0x1234();
	write_0x12345678();
}
