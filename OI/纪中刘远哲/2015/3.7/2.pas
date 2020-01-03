const	maxn=500000;
type	arr=array[0..maxn] of longint;
var	i,j,m,n,max,cnt,cnt1,ans,tmp:longint;
	a:arr;
	p:array[1..maxn] of boolean;
procedure qsort(var a1:arr;l,r:longint);
var	m,i,j:longint;
begin
	m:=a1[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while a1[i]>m do inc(i);
		while a1[j]<m do dec(j);
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
procedure dfs(dep:longint);
var	i:longint;
begin
	if dep>n then begin
		if ans>max-tmp then ans:=max-tmp;
		exit;
	end;
	if (dep<>1) and (a[dep-1]<>a[dep]) then begin
		inc(cnt,cnt1);
		cnt1:=0;
	end;
	for i:=0 to 1 do begin
		if odd(i) and (cnt>0) then begin
			dec(cnt);
			p[dep]:=false;
			dfs(dep+1);
		end else begin
			inc(cnt1);
			inc(tmp,a[dep]);
			p[dep]:=true;
			dfs(dep+1);
			dec(tmp,a[dep]);
		end;
	end;
end;
begin
	max:=0;ans:=maxlongint>>1;
	readln(n);
	for i:=1 to n do begin
		read(a[i]);
		inc(max,a[i]);
	end;
	qsort(a,1,n);
	dfs(1);
	writeln(ans);
end.
