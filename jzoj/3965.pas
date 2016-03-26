uses	math;
const	maxn=100000+5;maxm=6000000+2;
var	i,k,n,maxx,minx,miny,maxy,ans:longint;
	x,y,g:array[0..maxn] of longint;
	tree:array[1..4*maxm,1..2] of longint;
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure qsort(l,r:longint);
var	m,i,j:longint;
begin
	m:=x[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while x[i]<m do inc(i);
		while x[j]>m do dec(j);
		if i<=j then begin
			swap(x[i],x[j]);
			swap(y[i],y[j]);
			swap(g[i],g[j]);
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure change(x,l,r,st,en,val:longint);
var	mid:longint;
begin
	if (l=st) and (r=en) then begin
		inc(tree[x,1],val);inc(tree[x,2],val);
	end else begin
		inc(tree[x+x,1],tree[x,2]);inc(tree[x+x,2],tree[x,2]);
		inc(tree[x+x+1,1],tree[x,2]);inc(tree[x+x+1,2],tree[x,2]);
		tree[x,2]:=0;
		mid:=(r-l) div 2+l;
		if en<=mid then change(x+x,l,mid,st,en,val)
		else if st>mid then change(x+x+1,mid+1,r,st,en,val)
		else begin
			change(x+x,l,mid,st,mid,val);
			change(x+x+1,mid+1,r,mid+1,en,val);
		end;
		tree[x,1]:=max(tree[x+x,1],tree[x+x+1,1]);
	end;
end;
procedure init;
var	i,xx,yy:longint;
begin
	minx:=maxlongint;maxx:=-1;
	miny:=maxlongint;maxy:=-1;
	readln(n,k);
	for i:=1 to n do begin
		readln(g[i],xx,yy);
		x[i]:=xx+yy;
		y[i]:=yy-xx;
		if x[i]-k<minx then minx:=x[i]-k;
		if x[i]+k>maxx then maxx:=x[i]+k;
		if y[i]-k<miny then miny:=y[i]-k;
		if y[i]+k>maxy then maxy:=y[i]+k;
	end;
end;
procedure work;
var	l,r:longint;
begin
	qsort(1,n);
	l:=1;r:=1;ans:=0;
	for i:=minx to maxx do begin
		while (abs(x[r]-i)=k) and (r<=n) do begin
			change(1,miny,maxy,y[r]-k,y[r]+k,g[r]);
			inc(r);
		end;
		if tree[1,1]>ans then ans:=tree[1,1];
		while (x[l]+k=i) and (l<=n) do begin
			change(1,miny,maxy,y[l]-k,y[l]+k,-g[l]);
			inc(l);
		end;
	end;
	writeln(ans);
end;
begin
	assign(input,'3965.in');reset(input);
	//assign(output,'.out');rewrite(output);

	init;
	work;
end.
