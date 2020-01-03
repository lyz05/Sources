uses	math;
type
        Circle=
        record
                x,y,r:double;
        end;
const
        Maxn=305;
var
        map:array[1..Maxn,1..Maxn]of integer;
        Mark:array[1..Maxn,0..1]of longint;
        plane:array[1..Maxn]of Circle;
        n,Index:longint;
        Can:boolean;
function Distance(a,b:Circle):double;
begin
        exit(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
end;

function Calc(a,b:Circle):integer;
var
        c:Circle;
        x:double;
begin
        if a.y=b.y then
                exit(0);
        c:=plane[n+1];
        if c.y>=Max(a.y,b.y) then
                exit(0);
        if c.y<Min(a.y,b.y) then
                exit(0);
        x:=(c.y-a.y)/(b.y-a.y)*(b.x-a.x)+a.x;	//点c在直线上的x坐标值
	//x:=(0-2)/(-2-2)*(2--2)+-2=0
        if c.x<x then				//点c在直线的左边
                exit(1)
        else
                exit(0);
end;

procedure Walk(x:longint;s:integer);
var
        y:longint;
begin
        Mark[x,s]:=Index;
        for y:=1 to n do
                if (map[x,y]>=0) and (Mark[y,s xor map[x,y]]<Index) then
                        Walk(y,s xor map[x,y]);
end;

procedure Clear;
begin
        fillchar(map,sizeof(map),255);
        Can:=true;
end;

procedure Scanf;
var
        i:longint;
begin
        readln(n);
        for i:=1 to n do
                with plane[i] do
                        readln(x,y,r);
        with plane[n+1] do
                readln(x,y,r);
        for i:=1 to n do
                plane[i].r:=plane[i].r+plane[n+1].r;
end;

procedure Solve;
var
        i,j:longint;
begin
        for i:=1 to n-1 do
                for j:=i+1 to n do
                        if Distance(plane[i],plane[j])<plane[i].r+plane[j].r then
                        begin
                                map[i,j]:=Calc(plane[i],plane[j]);
                                map[j,i]:=map[i,j];
                        end;
        for i:=1 to n do begin
                Mark[i,0]:=0;
                mark[i,1]:=0;
        end;
        Index:=0;
        for i:=1 to n do
        begin
                inc(Index);
                Walk(i,0);
                for j:=1 to n do
                        if (Mark[j,0]=Index) and (Mark[j,1]=Index) then
                        begin
                                Can:=false;
                                break;
                        end;
                if not Can then
                        break;
        end;
end;

procedure Printf;
begin
        if Can then
                writeln('YES')
        else
                writeln('NO');
end;

begin
        assign(input,'3956.in');reset(input);
        //assign(output,'data.out');rewrite(output);
        while not eof do
        begin
                Clear;
                Scanf;
                Solve;
                Printf;
        end;
        //close(input);close(output);
end.
