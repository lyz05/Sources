uses	math;
const	maxn=50000;maxm=100000;
type	node=record
		y,next:longint;
	end;
var	stack,low,dfn,ans:array[0..maxn] of int64;
	e:array[0..maxn] of longint;
	h:array[0..2*maxm] of node;
	v:array[0..maxn] of boolean;
	i,x,y,time,tot,top,n,m:longint;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
function tarjan(x:longint):longint;
var	i,len,j:longint;
begin
	inc(top);
	stack[top]:=x;
	v[x]:=true;
	inc(time);
	dfn[x]:=time;
	low[x]:=time;
	tarjan:=0;
	i:=e[x];
	len:=n-1;
	while i<>0 do begin
		if not v[h[i].y] then begin
			j:=tarjan(h[i].y);
			inc(tarjan,j);
			if low[h[i].y]>=dfn[x] then begin
				inc(ans[x],j*(len-j));
				dec(len,j);
				while stack[top]<>h[i].y do begin
					stack[top]:=0;
					dec(top);
				end;
			end;
			low[x]:=min(low[x],low[h[i].y]);
		end else begin
			low[x]:=min(low[x],dfn[h[i].y]);
		end;
		i:=h[i].next;
	end;
	inc(tarjan);
	inc(ans[x],n-1);
end;
begin
	//assign(input,'3958.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		add(x,y);
		add(y,x);
	end;
	tarjan(1);
	for i:=1 to n do writeln(ans[i]);
end.
