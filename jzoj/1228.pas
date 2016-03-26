const	maxn=1000+5;
var	i,j,m,n,cnt,x,ans:longint;
	a:array[1..maxn,1..maxn] of shortint;
	b,c:array[1..maxn] of shortint;		//ÊÇ·ñ½»»»
function check:boolean;
var	i,j,tmp:longint;
begin
	for i:=1 to n do
		for j:=1 to m do begin
			tmp:=c[i] xor b[j];
			if tmp<>a[i,j] then exit(false);		
		end;
	exit(true);
end;
begin
	assign(input,'1228.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to n do
		for j:=1 to m do begin
			read(x);
			if x>0 then a[i,j]:=0 else a[i,j]:=1;
		end;
	
	cnt:=0;ans:=-1;
	for j:=1 to m do
	       	if a[1][j]=1 then b[j]:=0 else begin
			b[j]:=1;inc(cnt);
		end;
	for j:=1 to n do
		if b[1]=1 then begin
			if a[j,1]=1 then c[j]:=0 else begin
				c[j]:=1;
				inc(cnt);
			end;
		end else begin
			if a[j][1]=1 then begin
				c[j]:=1;
				inc(cnt);
			end else c[j]:=0;	
		end;
	if ((ans=-1) or (cnt<=ans)) and (check) then ans:=cnt;

	cnt:=0;
	for j:=1 to m do
	       	if a[1][j]=0 then b[j]:=0 else begin
			b[j]:=1;inc(cnt);
		end;
	for j:=1 to n do
		if b[1]=1 then begin
			if a[j,1]=1 then c[j]:=0 else begin
				c[j]:=1;
				inc(cnt);
			end;
		end else begin
			if a[j][1]=1 then begin
				c[j]:=1;
				inc(cnt);
			end else c[j]:=0;	
		end;
	if ((ans=-1) or (cnt<=ans)) and (check) then ans:=cnt;
	
	if ans=-1 then writeln('impossible') else writeln(ans);
end.
