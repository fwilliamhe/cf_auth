# cf_tta
Calcualting the _tta param of codeforces in web request.
## Usage
Example:
```c++
#include "auth_tta.h"
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);
    int _tta = codeforces::get_tta("CFu22GLm");
    std::cout << _tta << '\n';
}
```
## More
The codes are decrypted from `codeforces.js`
```js
var _0xca4e = ["\x6C\x65\x6E\x67\x74\x68", "\x63\x68\x61\x72\x43\x6F\x64\x65\x41\x74", "\x66\x6C\x6F\x6F\x72"]; function ca76fd64a80cdc35(_0x87ebx2) {
        var _0x87ebx3 = 0; for (var _0x87ebx4 = 0; _0x87ebx4 < _0x87ebx2[_0xca4e[0]]; _0x87ebx4++) {
            _0x87ebx3 = (_0x87ebx3 + (_0x87ebx4 + 1) * (_0x87ebx4 + 2) * _0x87ebx2[_0xca4e[1]](_0x87ebx4)) % 1009; if (_0x87ebx4 % 3 === 0) { _0x87ebx3++; }
            if (_0x87ebx4 % 2 === 0) { _0x87ebx3 *= 2; }
            if (_0x87ebx4 > 0) { _0x87ebx3 -= Math[_0xca4e[2]](_0x87ebx2[_0xca4e[1]](Math[_0xca4e[2]](_0x87ebx4 / 2)) / 2) * (_0x87ebx3 % 5); }
            while (_0x87ebx3 < 0) { _0x87ebx3 += 1009; }
            while (_0x87ebx3 >= 1009) { _0x87ebx3 -= 1009; }
        }
        return _0x87ebx3;
    }
```
