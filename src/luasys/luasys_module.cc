
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "luasys_module.h"
#include "luasys.h"

namespace lua_module_luasys
{
static sol::table require_api(sol::this_state L)
{
    sol::state_view lua(L);
    sol::table module = lua.create_table();
    module.set_function("gettid",&Cluasys::gettid);
    module.set_function("getpid",&Cluasys::getpid);
    return module;
}
}

LUA_API int luaopen_luasys(lua_State* L)
{
    return sol::stack::call_lua(L, 1, lua_module_luasys::require_api);
}

LUA_API int require_luasys(lua_State* L)
{
    luaL_requiref(L, "luasys", luaopen_luasys, 0);
    printf("lua module: require luasys\n");
    return 1;
}