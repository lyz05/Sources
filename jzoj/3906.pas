type	node=record
		num,fa,deep,sum:longint;
		ch:array[0..100] of longint;
	end;
const	maxn=500000;
var 	i,j,k,m,n,x,y,z:longint;
	h:array[1..maxn] of node;
        ans:int64;
procedure swap(var x,y:longint);
var t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure add(x,y,z:longint);
begin
	if h[x].fa=0 then swap(x,y);
	h[y].fa:=x;
	h[y].num:=z;
	h[y].deep:=h[x].deep+1;
	inc(h[x].ch[0]);
	h[x].ch[h[x].ch[0]]:=y;
end;
procedure dfs(deep,x:longint);
var i,len,tmp,ch,max,anss:longint;
begin
	len:=h[x].ch[0];
	if len=0 then begin
		//h[x].sum:=h[x].num
		exit;
	end;
	tmp:=0;max:=0;anss:=0;
	for i:=1 to len do begin
		ch:=h[x].ch[i];
		dfs(deep+1,ch);
		tmp:=h[ch].sum+h[ch].num;
		if tmp>max then max:=tmp;
		inc(anss,tmp);
	end;
	anss:=max*len-anss;
        inc(ans,anss);
	h[x].sum:=max;
end;
begin
	assign(input,'3906.in');reset(input);
	readln(n);
	h[1].deep:=1;h[1].fa:=1;
	for i:=1 to n-1 do begin
		readln(x,y,z);
		add(x,y,z);
	end;
	dfs(1,1);
	writeln(ans);
end.
