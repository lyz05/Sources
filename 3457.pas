const	maxn=50;maxm=maxn;
var	i,j,k,m,n,r,c,tot,x,y,ans:longint;
	map:array[1..maxm,1..maxn] of char;
	link:array[1..maxm*maxn,1..maxn*maxm] of boolean;
	girl:array[1..maxn*maxm] of longint;
	v:array[1..maxn*maxm] of boolean;
function find(x:longint):boolean;
var	j:longint;
begin
	for j:=1 to n*m do begin
		if link[x][j] and (not v[j]) then begin
			v[j]:=true;
			if (girl[j]=0) or find(girl[j]) then begin
				girl[j]:=x;
				exit(true);
			end;
		end;
	end;
	exit(false);
end;
begin
	assign(input,'3457.in');reset(input);

	readln(m,n,r,c);
	for i:=1 to m do begin
		for j:=1 to n do begin
			read(map[i,j]);
		end;
		readln;
	end;
	tot:=0;
	for i:=1 to m do begin
		for j:=1 to n do begin
			if map[i,j]='x' then continue;
			inc(tot);
			for k:=1 to 4 do begin
				case k of
					1:begin x:=i+r;y:=j+c; end;
					2:begin x:=i+r;y:=j-c; end;
					3:begin x:=i+c;y:=j+r; end;
					4:begin x:=i+c;y:=j-r; end;
				end;
				if (x<=0)or(y<=0)or(x>m)or(y>n)or
				(map[x,y]='x') then continue;
				
				link[(i-1)*n+j,(x-1)*n+y]:=true;
			end;
		end;
	end;
	ans:=0;
	for i:=1 to m*n do begin
		fillchar(v,sizeof(v),0);
		if find(i) then inc(ans);
	end;
	ans:=tot-ans;
	writeln(ans);
end.
