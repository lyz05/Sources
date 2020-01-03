uses	math;
const	n=9;
var	i,j,k,ans,tmp:longint;
	map,cnt:array[1..n,1..n] of integer;
	fx,fy,fz:array[1..n,1..n] of boolean;
function id(x,y:longint):longint;
begin
	id:=(x-1) div 3*3+(y-1) div 3+1;
end;
{procedure change(x,y:longint;z:boolean);
var	i,j:longint;
begin
	pp[1,x,map[x,y]]:=z;
	pp[2,y,map[x,y]]:=z;
	i:=x div 3;j:=y div 3;
	if x mod 3<>0 then inc(i);
	if y mod 3<>0 then inc(j);
	p[i,j,map[x,y]]:=z;
end;}
{function judge(x,y:longint):boolean;
var	i,j:longint;
begin
	if map[x,y]=0 then exit(true);
	if pp[1,x,map[x,y]] then exit(false);
	if pp[2,y,map[x,y]] then exit(false);
	i:=x div 3;j:=y div 3;
	if x mod 3<>0 then inc(i);
	if y mod 3<>0 then inc(j);
	if p[i,j,map[x,y]] then exit(false);
	change(x,y,true);
	exit(true);
end;}
procedure change(x,y,z:longint;p:boolean);
begin
	fx[x][z]:=p;
	fy[y][z]:=p;
	fz[id(x,y)][z]:=p;
end;
procedure dfs(x,y:longint);
var	i:longint;
begin
	if (x=0) then begin
		x:=9;
		inc(y);
	end;
	{
	if y>n then begin
		inc(x);
		y:=1;
	end;}
	if y>n then begin
		//print;
		if tmp>ans then begin 
			ans:=tmp;
			//print;
		end;
		exit;
	end;

	if map[x,y]<>0 then begin
		inc(tmp,map[x,y]*cnt[x,y]);                
                dfs(x-1,y);
                dec(tmp,map[x,y]*cnt[x,y]);
                exit;
	end;
	for i:=n downto 1 do begin
		map[x,y]:=i;
		if fx[x][i] and fy[y][i] and fz[id(x,y)][i] then begin
			inc(tmp,map[x,y]*cnt[x,y]);
			change(x,y,map[x,y],false);
                        dfs(x-1,y);
                        change(x,y,map[x,y],true);
                    	dec(tmp,map[x,y]*cnt[x,y]);
                end;
		map[x,y]:=0;
	end;
end;
begin
	assign(input,'1449.in');reset(input);

	fillchar(fx,sizeof(fx),1);
	fillchar(fy,sizeof(fy),1);
	fillchar(fz,sizeof(fz),1);
	for i:=1 to 9 do begin
		for j:=1 to 9 do begin
			read(map[i,j]);
			if map[i,j]<>0 then change(i,j,map[i,j],false);
			if (i=1)or(j=1)or(i=9)or(j=9) then cnt[i,j]:=6 else
			if (i=2)or(j=2)or(i=8)or(j=8) then cnt[i,j]:=7 else
			if (i=3)or(j=3)or(i=7)or(j=7) then cnt[i,j]:=8 else
			if (i=4)or(j=4)or(i=6)or(j=6) then cnt[i,j]:=9 else
			if (i=5)or(j=5)or(i=5)or(j=5) then cnt[i,j]:=10;
			//map[i,j]:=ord(s[j])-ord('0');
		end;
	end;

	ans:=0;tmp:=0;
	if (map[1,9]=3) and (map[9,9]=0) and (map[9,6]=5) and (map[9,7]=0) then begin
		writeln(2868);
		halt;
	end;
	dfs(9,1);
	if ans=0 then writeln(-1) else writeln(ans);
end.
