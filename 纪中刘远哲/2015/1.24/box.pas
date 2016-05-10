const	maxn=50;maxm=50;
var	i,j,k,m,n,ans:longint;
	map:array[1..maxn,1..maxm] of char;
procedure putpep(x,y:longint);
begin
		if cnt<10 then begin
		case k of begin
			0:k:=k;
			1:begin
				inc(ans1,6);
				inc(ans2,75);
		  	  	inc(ans3,58);
			  	inc(cnt);
			  end;
		end;
	end;
end;
procedure putbox;
var	i,j:longint;
begin
	for i:=1 to n do 
		for j:=1 to m do begin
			if map[i,j]<>'.' then continue;
			map[i,j]:='O';
			putpep(i,j);
			mao[i,j]:='.';
		end;
end;
begin
	readln(n,m);
	for i:=1 to n do 
		for j:=1 to m do 
			read(map[i,j]);

	putbox(1,1);
	writeln(ans);
end.
