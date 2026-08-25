class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++){
            result <<= 1;       // make space for next bit
            result |= (n & 1);  // add LSB of n to result
            n >>= 1;            // move to next bit
        }
        return result;
    }
};
