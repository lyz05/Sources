uses 	math;
const	maxn=10000+10;maxm=1000;maxx=2139062143;
var	i,j,k,m,n,tmp,x1,ans,ansn,i1,kk:longint;
	x,y,l,r:array[1..maxn] of longint;
	f:array[0..maxn,0..maxm] of longint;
	p:boolean;
begin
	assign(input,'bird.in');reset(input);

	readln(n,m,k);
	for i:=1 to n do begin
		readln(x[i],y[i]);
                r[i]:=m+1;
	end;
	for i:=1 to k do begin
		read(x1);
		readln(l[x1],r[x1]);
	end;

        fillchar(f,sizeof(f),127);
	for i:=1 to m do f[1,i]:=0;
	for i:=2 to n+1 do begin
		j:=1;
		while j<m do begin
			if j-x[i-1]>0 then begin
				f[i,j]:=min(f[i,j],f[i-1,j-x[i-1]]+1);
				f[i,j]:=min(f[i,j],f[i,j-x[i-1]]+1);
			end;
			if (f[i,j]<>maxx) and (j>l[i-1]) and (j<r[i-1]) then ansn:=i;
			inc(j);
		end;
		if r[i]=m+1 then begin
			for j:=m-x[i-1] to m do begin
				f[i,m]:=min(f[i,m],f[i-1,j]+1);
				if j<>m then f[i,m]:=min(f[i,m],f[i,j]+1);
			end;
		end;
		j:=1;
		while j<m do begin
			if j+y[i-1]<=m then
				f[i,j]:=min(f[i,j],f[i-1,j+y[i-1]]);
			if (f[i,j]<>maxx) and (j>l[i-1]) and (j<r[i-1]) then ansn:=i;
			inc(j);
		end;
		if l[i-1]<>m+1 then begin
			for j:=1 to l[i-1] do f[i,j]:=maxx;
			for j:=r[i-1] to m do f[i,j]:=maxx;
		end;
		if (f[i,m]<>maxx) and (r[i-1]<>m+1) then ansn:=i;
	end;

	if ansn=n+1 then begin
		ans:=maxx;
		for i:=1 to m do
			if f[n+1,i]<ans then ans:=f[n+1,i];
		writeln(1);
		writeln(ans);
	end else begin
                writeln(0);
		ans:=0;
		for i:=1 to ansn do
			if r[i]<>m+1 then inc(ans);
		writeln(ans);
	end;
        for i:=1 to 17 do
        begin
                for j:=1 to 5 do write(f[i,j],' ');
                writeln;
        end;
	//close(input);
end.
