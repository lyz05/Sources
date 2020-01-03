const	maxn=20+5;
type	arr=array[0..maxn,1..2] of longint;
var	i,j,k,m,n,ans,x:longint;
	//a:array[1..maxn,1..3] of longint;
	a:Array[1..maxn] of boolean;
	b,c:arr;
	p:array[1..maxn] of boolean;
procedure qsort(var a1:arr;l,r:longint);
var	i,j,m:longint;
begin
	m:=a1[(l+r)>>1,1];
	i:=l;
	j:=r;
	repeat
		while (a1[i,1]>m) do inc(i);
		while (a1[j,1]<m) do dec(j);
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
procedure check;
var	i,cnt1,cnt2,tmp:longint;
begin
	cnt1:=k;
	cnt2:=k;
	tmp:=0;
	for i:=1 to n do begin
		if (cnt1>0) and (p[b[i,2]]) then begin
			dec(cnt1);
			if a[b[i,2]] then inc(tmp,b[i,1]);
		end;
		if (cnt2>0) and (not p[c[i,2]]) then begin
			dec(cnt2);
                        if a[c[i,2]] then inc(tmp,c[i,1]);
		end;
		if (cnt1=0) and (cnt2=0) then break;
	end;
	if tmp>ans then ans:=tmp;
end;
procedure dfs(dep:longint);
var	i:longint;
begin
	if dep>n then begin
		check;
		exit;
	end;
	for i:=1 to 2 do begin
		if i=1 then p[dep]:=true else p[dep]:=false;
		dfs(dep+1);
	end;
end;
begin
	assign(input,'planetcup.in');reset(input);
	assign(output,'planetcup.out');rewrite(output);

	readln(n,k);
	for i:=1 to n do begin
		//readln(a[i,1],a[i,2],a[i,3]);
		readln(b[i,1],c[i,1],x);
		b[i,2]:=i;c[i,2]:=i;
		if odd(x) then a[i]:=true;
	end;
	qsort(b,1,n);qsort(c,1,n);
	dfs(1);
        writeln(ans);

	close(input);close(output);
end.
