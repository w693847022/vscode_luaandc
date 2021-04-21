extern "C"
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}
class LuaTest{
public:
    LuaTest(){};
    ~LuaTest(){};
public:
    void Test_1()
    {
        printf("main: toLua\n");
        for(int i = 0;i<10 ;i++)
        {
            printf("%d|",i);
        }
        printf("\n");
        lua_State *pLua = luaL_newstate();
        luaL_openlibs(pLua);
        if(luaL_dofile(pLua,"main.lua")==1)
        {
            const char * msg = lua_tostring(pLua,-1);
            printf("%s\n",msg);
        }
        getchar();
    }
};