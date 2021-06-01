#include <assert.h>
#include "main.h"
void _main()
{
	assert(Letters("qwerty") == "More consonants");
	assert(Letters("eeeeee") == "More vowels");
	assert(Letters("asdcf") == "More consonants");
	assert(Letters("puy") == "More vowels");
	assert(Letters("qwea") == "Vowels = consonants");
	assert(Letters("ighu") == "Vowels = consonants");
}