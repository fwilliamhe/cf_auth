# cf_auth
Calcualting the _tta / bfaa / ftaa params of codeforces in web request.
## Usage
Example:
```c++
#include "auth.h"
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);
    std::cout << "_tta : " << codeforces::get_tta("CFu22GLm") << '\n';
    std::cout << "bfaa : " << codeforces::generate_bfaa() << '\n';
    std::cout << "ftaa : " << codeforces::generate_ftaa() << '\n';
}
```
Example output:
```bash
_tta : 619
bfaa : c6877ce2f8c827a8dbe8515403a0cefc
ftaa : fdixxhy2itobjl6m4k
```
## Details

1. Codeforces use `X-Csrf-Token` to prevent cross site request forgery. The token is stored in `<meta name = "X-Csrf-Token">` . We can simply get it by sending `GET` request to Codeforces homepage.

2. Codeforces use `evercookie` to store some information like `ftaa` and `bfaa`, which are the necessary fields for signing in. Here is the source (Js):

   ``` html
   <script src="//codeforces.org/s/86968/js/ftaa.js" type="text/javascript"></script>
   <script type="text/javascript">
       $(function() {
           if (window.evercookie) {
               var ec = new evercookie({
                   history: false,
                   silverlight: false,
                   baseurl: '',
                   asseturi: '/assets',
                   phpuri: '/2fdcd78',
                   pngPath: '/eps',
                   etagPath: '/ees',
                   cachePath: '/ecs'
               });
   
               var randomNumber = function () {
                   return Math.random().toString(36).substr(2);
               };
   
               var randomToken = function () {
                   return (randomNumber() + randomNumber()).substring(0, 18);
               };
   
               window._ftaa = "";
   
               ec.get("70a7c28f3de", function (value) {
                   window._ftaa = value;
                   if (!window._ftaa) {
                       window._ftaa = randomToken();
                       ec.set("70a7c28f3de", window._ftaa);
                   }
                   $.post("/data/empty", {bfaa: window._bfaa, ftaa: window._ftaa});
               });
           } else {
               window._ftaa = "n/a";
               $.post("/data/empty", {bfaa: window._bfaa, ftaa: window._ftaa});
           }
       });
   </script>
   
   <script src="//codeforces.org/s/86968/js/bfaa.js" type="text/javascript"></script>
   
   <script type="text/javascript">
       $(function() {
           var fpCallback = function() {
               Fingerprint2.get({}, function(components) {
                   window._bfaa = Fingerprint2.x64hash128(components.map(function (pair) { return pair.value }).join(), 31);
                   $.post("/data/empty", {bfaa: window._bfaa, ftaa: window._ftaa});
               });
           };
           if (typeof Fingerprint2 !== 'undefined') {
               if (window.requestIdleCallback) {
                   requestIdleCallback(fpCallback)
               } else {
                   setTimeout(fpCallback, 500)
               }
           } else {
               window._bfaa = "n/a";
               $.post("/data/empty", {bfaa: window._bfaa, ftaa: window._ftaa});
           }
       });
   </script>
   ```

    `ftaa` is actually a random string and `bfaa` is the `hash128` value of the fingerprint of the bowser you use. 

3. `_tta` is a self-designed checksum of cookie `39ce7`, it is calculated in a encrypted js.


## Reference
md5 library from [injae](https://github.com/injae/md5/)

## License 

GPLv3

## Buy me a coffee
\^ \_ \+