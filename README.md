# A-Star Algorithm
这是使用C++实现的高效的A-Star算法。只对算法的程序实现做了尽力而为的优化，并没有对算法自身进行改良。优化措施主要在于：快速判断路径节点是否在开启/关闭列表中、快速查找最小f值的节点以及优化路径节点频繁分配内存的问题。

添加了测试程序以及如何利用Cmake链接库的示例。

# 运行
```shell
git clone https://github.com/KunSong-L/a-star-algorithm.git
cd a-star-algorithm
mkdir build
cd build
cmake ..
make 
./test
```

# 使用示例
```c++
//注意利用AStar::Vec2索引地图下标为maps[y][x]

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
```
