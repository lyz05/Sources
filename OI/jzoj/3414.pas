type	node=record
		y,next,val:longint;
	end;
const 	maxn=300+5;maxm=5000+5;
var	i,j,k,m,n,x,y,v1,v2,tot,ans:longint;
	e:array[1..maxn] of longint;
	h:array[1..2*maxm] of node;
	flag:array[1..maxn] of boolean;
procedure add(x,y,val:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].val:=val;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure dfs(x,sum,num:longint);
var	j:longint;
begin
	if sum<0 then exit;
	if num>ans then exit;
	if (x=i) and (flag[i]) then begin
		if (sum>0) and (num<ans) then ans:=num;
		exit;
	end;
	flag[x]:=true;
	j:=e[x];
	while j<>0 do begin
		if (not flag[h[j].y]) or (h[j].y=i) then 
			dfs(h[j].y,sum+h[j].val,num+1);
		j:=h[j].next;
	end;
	flag[x]:=false;
end;
begin
	assign(input,'3414.in');reset(input);
	readln(n,m);
	for i:=1 to m do begin
		readln(x,y,v1,v2);
		add(x,y,v1);
		add(y,x,v2);
	end;
	ans:=maxlongint;
	for i:=1 to n do dfs(i,0,0);
	writeln(ans);
end.
