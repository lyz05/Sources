const	maxn=20000;
type	sz=array[0..maxn,1..2] of longint;
var	i,j,k,m,n,edge,ans:longint;
	a:sz;
	s:array[0..8,1..maxn] of longint;
	del:array[0..maxn] of longint;
	p:array[1..maxn] of boolean;
procedure qsort(var a1:sz;l,r:longint);
var m,i,j:longint;
begin
	m:=a1[(l+r) div 2,1];
	i:=l;j:=r;
	repeat
		while a1[i,1]<m do inc(i);
		while a1[j,1]>m do dec(j);
		if i<=j then begin
			a1[0]:=a1[i];
			a1[i]:=a1[j];
			a1[j]:=a1[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(a1,l,j);
	if i<r then qsort(a1,i,r);
end;
procedure calc;
var	fir,m,k:longint;
begin
	fir:=edge-(8-del[0]);
	k:=1;
	while fir>=0 do begin
		for i:=1 to del[0] do 
			if s[del[i],edge]<>s[del[i],fir] then exit;
		m:=k;
		for i:=1 to 8 do 
			if (s[i,edge]-s[i,fir]>m) and (not p[i]) then m:=s[i,edge]-s[i,fir];
		if m=k then begin
			if a[edge,1]-a[fir+1,1]>ans then ans:=a[edge,1]-a[fir+1,1];
			fir:=fir-(8-del[0]);
			inc(k);
		end else begin
			fir:=edge-m*(8-del[0]);
			k:=m;
		end;
	end;
end;
procedure dfs(x:longint);
begin
	if x>8 then begin
		calc;
		exit;
	end;
	if del[0]<8-k then begin
		p[x]:=true;
		inc(del[0]);
		del[del[0]]:=x;
		dfs(x+1);
		del[del[0]]:=0;
		dec(del[0]);
		p[x]:=false;
	end;
	dfs(x+1);
end;
begin
	assign(input,'3952.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,k);
	for i:=1 to n do readln(a[i,1],a[i,2]);
	qsort(a,1,n);
	for i:=1 to n do begin
		inc(s[a[i,2],i]);
		for j:=1 to 8 do inc(s[j,i],s[j,i-1]);
	end;
	ans:=-1;
	for edge:=1 to n do dfs(1);
	writeln(ans);
end.
