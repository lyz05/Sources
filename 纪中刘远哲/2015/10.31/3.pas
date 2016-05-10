const	inf:array[0..9,0..1,1..5] of longint=
	(((3,2,2,2,3),(5,2,5,0,0)),
	((1,1,1,1,1),(5,0,0,0,0)),
	((3,1,3,1,3),(4,3,4,0,0)),
	((3,1,3,1,3),(3,3,5,0,0)),
	((1,2,4,1,1),(1,2,5,1,0)),
	((3,1,3,1,3),(4,3,4,0,0)),
	((3,1,3,2,3),(5,3,4,0,0)),
	((3,1,1,1,1),(1,1,5,0,0)),
	((3,2,3,2,3),(5,3,5,0,0)),
	((3,2,3,1,1),(3,2,5,0,0)));
var	s:array[1..6] of ansistring;		//change
	x,y,n,i:longint;
	xx,yy:array[1..6] of longint;
procedure print(x:longint);
begin
	write(x,' ');
end;
procedure work(x,y:longint);
var	p,q:longint;
	i,j,k:longint;
	flag:boolean;
begin
	for i:=1 to 6 do begin
		xx[i]:=0;
		for j:=1 to 6 do begin
			if (s[x+i][y+j]='.') then inc(xx[i]);
		end;
	end;
	for j:=1 to 6 do begin
		yy[j]:=0;
		for i:=1 to 6 do begin
			if (s[x+i][y+j]='.') then inc(yy[j]);
		end;
	end;

	j:=1;
	while xx[j]=0 do inc(j);
	p:=j;
	j:=1;
	while yy[j]=0 do inc(j);
	q:=j;

	for i:=0 to 10 do begin
		flag:=true;
		for k:=p to p+5-1 do begin
			if xx[k]<>inf[i][0][k-p+1] then 
			begin
				flag:=false;
				break;
			end;
		end;
		if not flag then continue;
		for k:=q to q+5-1 do begin
			if yy[k]<>inf[i][1][k-q+1] then 
			begin
				flag:=false;
				break;
			end;
		end;
		if flag then begin
			if (i=2) or (i=5) then begin
				if s[x+p+1][y+q]='.' then print(5)
				else print(2);
			end else print(i);
			break;
		end;
	end;
end;
begin
	assign(input,'captcha.in');reset(input);
	//assign(output,'captcha.out');rewrite(output);

	readln(n);
	for i:=1 to 6 do readln(s[i]);

	x:=0;y:=0;
	for i:=1 to n do begin
		work(x,y);
		y:=y+7;
	end;

	close(input);close(output);
end.
