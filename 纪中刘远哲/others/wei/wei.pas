const 	maxn=500000;

var 	i,j,k,m,n,tmp,anss,max,maxa:longint;
	a:array[0..maxn,1..3] of longint;
	p:array[1..maxn] of boolean;
	b,ans:array[0..maxn] of longint;
procedure qsort(l,r:longint);
var i,j,m:longint;
begin
	i:=l;
	j:=r;
	m:=a[(l+r) div 2,1];
	repeat
		while a[i,1]<m do inc(i);
		while a[j,1]>m do dec(j);
		if i<=j then begin
			a[0]:=a[i];
			a[i]:=a[j];
			a[j]:=a[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure fz(x,y,z:longint);
var i:longint;
begin
	for i:=b[x] to b[x+1]-1 do
		if a[i,2]=y then a[i,3]:=z;
end;
procedure dfs(deep,x:longint);
var     i,j:longint;
        pp:boolean;
begin
        p[x]:=true;
        pp:=false;
	if deep>n then begin
		inc(ans[0]);
		ans[ans[0]]:=tmp;
		if tmp>max then begin
			max:=tmp;
		end;
		exit;
	end;
	for i:=b[x] to b[x+1]-1 do begin
		if not p[a[i,2]] then begin
			p[a[i,2]]:=true;
			inc(tmp,a[i,3]);
				dfs(deep+1,a[i,2]);
			dec(tmp,a[i,3]);
			p[a[i,2]]:=false;
                        pp:=true;
		end;
	end;
        if not pp then begin
		inc(ans[0]);
		ans[ans[0]]:=tmp;
		if tmp>max then begin
			max:=tmp;
		end;
		exit;
        end;
        p[x]:=false;

end;
begin
assign(input,'wei.in');reset(input);
assign(output,'wei.out');rewrite(output);

	readln(n);
	for i:=1 to n-1 do begin
		readln(a[i,1],a[i,2],a[i,3]);
		a[i+n-1,1]:=a[i,2];
		a[i+n-1,2]:=a[i,1];
		a[i+n-1,3]:=a[i,3];
	end;
	qsort(1,2*n-2);
	k:=0;j:=0;
	for i:=1 to 2*n-2 do
		if a[i,1]<>k then begin
			k:=a[i,1];
			b[k]:=i;
                        j:=i;
		end;
	b[n+1]:=2*n-2+1;
	dfs(1,1);
	anss:=0;
	for i:=1 to ans[0] do begin
		inc(anss,max-ans[i]);
	end;
	writeln(anss);

close(input);close(output);
end.
