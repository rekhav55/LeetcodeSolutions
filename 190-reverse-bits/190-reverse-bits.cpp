class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int rev= 0;
					for (short i = 0; i < 32; i++) 
					{
						if ((n & (1 << i)))
							rev |= 1 << ((32 - 1) - i);
					}
					return rev;
    }
};