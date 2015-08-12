var	i,j,k,m,n,tot,x,q1,q2,v:longint;
	a,t,c,d,g:array[0..100002] of longint;
procedure find(z:longint);
var	l,r,mid:longint;
begin
	l:=1;
	r:=tot;
	while (l<r) do begin
		mid:=(l+r)>>1;
		if (z<g[mid]) then r:=mid else l:=mid+1;
	end;
	x:=l;
end;
procedure qsort(l,r:longint);
var	m,m1,i,j,t:longint;
begin
	m:=c[(l+r) div 2];
	m1:=d[(l+r) div 2];
	i:=l;j:=r;
	repeat
		while (c[i]<m) or ((c[i]=m) and (d[i]<m1)) do inc(i);
		while (c[j]>m) or ((c[j]=m) and (d[j]>m1)) do dec(j);
		if i<=j then begin
			t:=c[i];
			c[i]:=c[j];
			c[j]:=t;
			t:=d[i];
			d[i]:=d[j];
			d[j]:=t;
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
begin
	assign(input,'3465.in');reset(input);

	readln(n);
	for i:=1 to n do readln(a[i],t[i]);
	readln(v);
	for i:=1 to n do begin
		c[i]:=t[i]*v-a[i];
		d[i]:=t[i]*v+a[i];
	end;
	
	qsort(1,n);
	tot:=0;
	g[0]:=-maxlongint;
	for i:=1 to n do begin
		if (d[i]>=g[tot]) then begin
			inc(tot);
			g[tot]:=d[i];
		end else begin
			find(d[i]);
			g[x]:=d[i];
		end;
	end;
	q2:=tot;
	
	fillchar(g,sizeof(g),0);
	tot:=0;
	g[0]:=-maxlongint;
	for i:=1 to n do begin
		if (d[i]>=0) and (c[i]>=0) then begin
			if (d[i]>=g[tot]) then begin
				inc(tot);
				g[tot]:=d[i];
			end else begin
				find(d[i]);
				g[x]:=d[i];
			end;
		end;
	end;
	q1:=tot;
	writeln(q1,' ',q2);
end.
