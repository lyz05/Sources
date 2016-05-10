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
{ �ڽӾ���, infinity��ʾû�б����� }
  path : array [1..maxp] of longint;
{ ·������, ��¼��Դ������ľ������·�� }
  source : longint;
{ Դ����� }

procedure dijkstra;
var
  dist : array [1..maxp] of longint;
{ ��������, ��¼Ŀǰ��Դ������Ѿ��ҵ������·������ }
  visited : array [1..maxp] of boolean;
{ ��־����, ��¼�Ƿ��Ѿ��ҵ���ĳһ����������·�� }
  i, j, min, minp : longint;

begin
  source:=1;
  fillchar(visited, sizeof(visited), 0);{��ʼ��Դ���·������}
  for i:=1 to maxp do
  begin
    dist[i]:=map[source,i];
    if dist[i]<m then
      path[i]:=source
    else
      path[i]:=0;
  end;

{ Դ������·���϶��ǲ����ҵ�...}
  visited[source]:=true;

{ dijkstra��˼���ǰ���������������·��, ÿ��ѡ����ǰ�Ѿ�
  �ҵ�����̵�һ��·��, ����Ȼ��һ�����յ����·��. ���
  ÿ���ҳ���ǰ������������С��, ��Ȼ��һ�����յ����·�� }
  for i:=2 to maxp do
  begin
    min:=infinity; minp:=0;
    for j:=1 to maxp do
    if (not visited[j]) and (dist[j]<min) then
    begin
      min:=dist[j]; minp:=j;
    end;

{ ���ҵ�Դ�㵽��minp�����·��, ���ϱ�־ }
    visited[minp]:=true;

{ �޸ľ������� }
    for j:=1 to maxp do
    if (not visited[j]) and (dist[j]-dist[minp]>map[minp,j]) then
    begin
      dist[j]:=dist[minp]+map[minp,j]; path[j]:=minp;
    end;
  end;
end;
