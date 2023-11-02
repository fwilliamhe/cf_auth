/*
 Copyright (c) 2023 William He (https://github.com/fwilliamhe/)

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <cstring>

/* 
Get tta for codeforces
Notes : cookie is cookies['39ce7']
Upd time : Nov 1 2023 19:52:51 (PDT)
*/
namespace codeforces {
    int get_tta(std::string cookie) {
        int tta = 0; const int P = 1009;
        for (int i = 0; i < cookie.length(); ++i) {
            tta = (tta + (i + 1) % P * (i + 2) % P * cookie[i] % P) % P;
            if (i % 3 == 0) (tta += 1) %= P;
            if (i % 2 == 0) (tta *= 2) %= P;
            if (i > 0) (tta -= (cookie[i / 2] / 2) % P * (tta % 5) % P - P ) %= P;
        }
        return tta;
    }
}
