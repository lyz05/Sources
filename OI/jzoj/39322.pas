var
	d:array[0..10000,1..3] of longint;
	a:array[1..10000,1..2] of longint;
	f:array[0..10010,1..1000] of longint;
	n,m,k,i,j,t,ans,anst,t0:longint;

function min(x,y:longint):longint;
begin
	if x<y then exit(x)
	else exit(y);
end;

procedure sort(x,y:longint);
var
	i,j,ran:longint;
begin
	i:=x; j:=y;
	ran:=d[random(y-x+1)+x,1];
	while i<=j do begin
		while d[i,1]<ran do inc(i);
		while ran<d[j,1] do dec(j);
		if i<=j then begin
			d[0]:=d[i];
			d[i]:=d[j];
			d[j]:=d[0];
			inc(i); dec(j);
		end;
	end;
	if i<y then sort(i,y);
	if x<j then sort(x,j);
end;

begin
        assign(input,'bird.in');reset(input);
	readln(n,m,k);
	for i:=1 to n do readln(a[i,1],a[i,2]);
	for i:=1 to k do begin
		readln(d[i,1],d[i,2],d[i,3]);
		inc(d[i,1]);
	end;
	sort(1,k);

	d[0,1]:=0;
	fillchar(f,sizeof(f),60);
	t0:=f[1,1];
	anst:=0;
	t:=1;
	for i:=1 to m do f[1,i]:=0;
	for i:=2 to n+1 do begin
		while (t<=k) and (i>d[t,1]) do inc(t);
		j:=1;
		while j<m do begin
			if j-a[i-1,1]>0 then begin
				f[i,j]:=min(f[i,j],f[i-1,j-a[i-1,1]]+1);
				f[i,j]:=min(f[i,j],f[i,j-a[i-1,1]]+1);
			end;
			if (f[i,j]<>t0) and (i=d[t,1]) and (j>d[t,2]) and (j<d[t,3]) then anst:=t;
			inc(j);
		end;
		if not(i=d[t,1]) then
		for j:=m-a[i-1,1] to m do begin
			f[i,m]:=min(f[i,m],f[i-1,j]+1);
			if j<>m then f[i,m]:=min(f[i,m],f[i,j]+1);
		end;
		j:=1;
		while j<m do begin
			if j+a[i-1,2]<=m then
				f[i,j]:=min(f[i,j],f[i-1,j+a[i-1,2]]);
			if (f[i,j]<>t0) and (i=d[t,1]) and (j>d[t,2]) and (j<d[t,3]) then anst:=t;
			inc(j);
		end;
		if i=d[t,1] then begin
			for j:=1 to d[t,2] do f[i,j]:=t0;
			for j:=d[t,3] to m do f[i,j]:=t0;
		end;
		if (f[i,m]<>t0) and (i=d[t,1]) then anst:=t;
	end;

	if anst=k then begin
		ans:=maxlongint;
		writeln(1);
		for i:=1 to m do if f[n+1,i]<ans then begin
                        ans:=f[n+1,i];
                end;
		writeln(ans);
	end
	else begin
		writeln(0);
		writeln(anst);
	end;
        for i:=1 to 17 do
        begin
                for j:=1 to 5 do write(f[i,j],' ');
                writeln;
        end;
end.
