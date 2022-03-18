#include "./astar/astar.h"
#include "./astar/blockallocator.h"
#include <iostream>

int main()
{
        char maps[10][10] =
    {
        { 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
        { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
        { 1, 1, 0, 0, 1, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
    };

    // 搜索参数
    AStar::Params param;
    param.width = 10;
    param.height = 10;
    param.corner = false;
    param.start = AStar::Vec2(0, 0);
    param.end = AStar::Vec2(9, 9);
    param.can_pass = [&](const AStar::Vec2 &pos)->bool
    {
        return maps[pos.y][pos.x] == 0;
    };

    // 执行搜索
    BlockAllocator allocator;
    AStar algorithm(&allocator);
    auto path = algorithm.find(param);

    //start point
    maps[0][0] = 8;
    for(AStar::Vec2 p:path)
    {
        maps[p.y][p.x] = 8;
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            std::cout<<int(maps[i][j])<<"  ";
        }
        std::cout<<std::endl;
    }
}