uses	math;
const	maxn=100000+2;maxm=500000+2;
var	i,j,k,m,n,top,tot,ans,t,x,y:longint;
	e:array[1..maxn] of longint;
	next,go:array[1..maxm] of longint;
	vx,vy:array[1..maxn] of longint;
	s:array[1..maxn,1..2] of longint;
	tree:array[1..4*maxn] of longint;
procedure add(x,y:longint);
begin
	inc(tot);
	go[tot]:=y;
	next[tot]:=e[x];
	e[x]:=tot;
end;
procedure change(p,l,r,x,y:longint);
var	mid:longint;
begin
	if l=r then begin
		if y>tree[p] then tree[p]:=y;
		exit;
	end;
	mid:=(l+r)>>1;
	if x<=mid then change(p*2,l,mid,x,y) else change(p*2+1,mid+1,r,x,y);
	tree[p]:=max(tree[p*2],tree[p*2+1]);
end;
function quary(p,l,r,st,en:longint):longint;
var	mid:longint;
begin
	if st>en then exit(0);
	if (l=st) and (r=en) then begin
		exit(tree[p]);
	end;
	mid:=(l+r)>>1;
	if en<=mid then exit(quary(p*2,l,mid,st,en)) else 
	if mid<st then exit(quary(p*2+1,mid+1,r,st,en))
	else exit(max(quary(p*2,l,mid,st,mid),quary(p*2+1,mid+1,r,mid+1,en)));
end;
begin
	assign(input,'4006.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		add(x,y);
	end;
	for i:=1 to n do read(vy[i]);
	for i:=1 to n do read(vx[i]);

	ans:=0;
	for i:=1 to n do begin
		top:=0;j:=e[i];
		while j<>0 do begin
			t:=quary(1,1,n,1,go[j]-1)+vx[i]+vy[go[j]];
			if t>ans then ans:=t;
			inc(top);
			s[top,1]:=go[j];
			s[top,2]:=t;
			j:=next[j];
		end;
		while top>0 do begin
			change(1,1,n,s[top,1],s[top,2]);
			dec(top);
		end;
	end;
	writeln(ans);
end.
