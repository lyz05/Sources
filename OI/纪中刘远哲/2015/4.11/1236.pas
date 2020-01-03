const	maxn=20;
type	node=record
		x,y:longint;
	end;
var	i,j,k,m,n:longint;
	a:array[1..maxn,1..maxn] of double;
	f:array[0..1 shl maxn] of double;
	d:array[0..1 shl maxn+1] of node;
	b:array[0..1 shl maxn+1] of boolean;
procedure work;
var	l,r,i,j,cnt,x,num:longint;
begin
	d[0].x:=0;d[0].y:=1;
	l:=0;r:=0;
	while l<=r do begin
		x:=d[l].x;num:=d[l].y;
		b[x]:=false;
		for i:=1 to n do begin
			if (1<<(i-1)) and x=0 then 
			if f[x]*a[i,num]>f[x or (1<<(i-1))] then begin
				f[x or (1<<(i-1))]:=f[x]*a[i,num];
				if not b[x or (1<<(i-1))] then begin
					b[x or (1<<(i-1))]:=true;
					inc(r);
					d[r].x:=x or (1<<(i-1));
					d[r].y:=num+1;
				end;
			end;
		end;
		inc(l);
	end;
end;
begin
	assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
	for i:=1 to n do 
		for j:=1 to n do begin
			read(a[i,j]);
			a[i,j]:=a[i,j]/100;
		end;
	f[0]:=1;
	work;
	writeln(f[(1<<n)-1]*100:0:6);
end.
