program ex_dijkstra;
const
  maxp=5;
  infinity=maxlongint;
  m=maxlongint;
  map:array [1..5,1..5] of longint =
         ((m,10,m,30,100),
          (m,m,50,m,m),
          (m,m,m,m,10),
          (m,m,20,m,60),
          (m,m,m,m,m));

var
{  map : array [1..maxp, 1..maxp] of longint;}
{ 邻接矩阵, infinity表示没有边相连 }
  path : array [1..maxp] of longint;
{ 路径数组, 记录从源点出发的具体最短路径 }
  source : longint;
{ 源点变量 }

procedure dijkstra;
var
  dist : array [1..maxp] of longint;
{ 距离数组, 记录目前从源点出发已经找到的最短路径长度 }
  visited : array [1..maxp] of boolean;
{ 标志数组, 记录是否已经找到了某一点的最终最短路径 }
  i, j, min, minp : longint;

begin
  source:=1;
  fillchar(visited, sizeof(visited), 0);{初始化源点和路径数组}
  for i:=1 to maxp do
  begin
    dist[i]:=map[source,i];
    if dist[i]<m then
      path[i]:=source
    else
      path[i]:=0;
  end;

{ 源点的最短路径肯定是不用找的...}
  visited[source]:=true;

{ dijkstra的思想是按递增长度来产生路径, 每次选出当前已经
  找到的最短的一条路径, 它必然是一条最终的最短路径. 因此
  每次找出当前距离数组中最小的, 必然是一条最终的最短路径 }
  for i:=2 to maxp do
  begin
    min:=infinity; minp:=0;
    for j:=1 to maxp do
    if (not visited[j]) and (dist[j]<min) then
    begin
      min:=dist[j]; minp:=j;
    end;

{ 已找到源点到点minp的最短路径, 做上标志 }
    visited[minp]:=true;

{ 修改距离数组 }
    for j:=1 to maxp do
    if (not visited[j]) and (dist[j]-dist[minp]>map[minp,j]) then
    begin
      dist[j]:=dist[minp]+map[minp,j]; path[j]:=minp;
    end;
  end;
end;
