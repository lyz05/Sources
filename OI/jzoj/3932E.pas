uses 	math;
const	maxn=10000+10;maxm=1000;maxx=2139062143;
var	i,j,k,m,n,tmp,x1,ans,ansn,i1,kk:longint;
	x,y,l,r:array[1..maxn] of longint;
	f:array[0..maxn,0..maxm] of longint;
	p:boolean;
begin
	//assign(input,'bird.in');reset(input);

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
	for i:=1 to m do begin
		for j:=1 to ((m-i) div x[1]) do begin
			tmp:=i+j*x[1];
			f[1,tmp]:=min(f[1,tmp],j);
		end;
		if i>y[1] then f[1,i-y[1]]:=0;
		f[1,m]:=min(f[1,m],((m-j) div x[1])+1);
	end;
	for i:=1 to n-1 do begin
		i1:=i+1;
		p:=false;
		for j:=l[i]+1 to r[i]-1 do begin
			if f[i,j]<>maxx then begin
				p:=true;
				for kk:=1 to ((m-j) div x[i1]) do begin
					tmp:=j+kk*x[i1];
					f[i1,tmp]:=min(f[i1,tmp],f[i,j]+kk);
				end;
				if j>y[i1] then f[i1,j-y[i1]]:=f[i,j];
				f[i1,m]:=min(f[i1,m],f[i,j]+((m-j) div x[i1])+1);
				{	k:=1;
				while true do begin
					tmp:=j-k*x[i];
					if tmp<=0 then break;
					f[i,j]:=min(f[i-1,tmp]+k,f[i,j]);
					inc(k);
				end;
				tmp:=j+y[i];
				if tmp<=m then
					f[i,j]:=min(f[i-1,tmp],f[i,j]);
				if i=n then ans:=min(ans,f[i,j]);
				if (ansn<>i) and (f[i,j]<>maxx) then
					ansn:=i;
				end;}
			end;

		end;
		if p then ansn:=i;
	end;
	ans:=maxx;
	for i:=l[n]+1 to r[n]-1 do
		if f[n,i]<ans then ans:=f[n,i];

	if ans<>maxx then begin
		writeln(1);
		writeln(ans);
	end else begin
		writeln(0);
		ans:=0;
		for i:=1 to ansn do
			if r[i]<>m+1 then inc(ans);
		writeln(ans);
	end;
	//close(input);
end.
