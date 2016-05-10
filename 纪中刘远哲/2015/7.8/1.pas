type	arr=array[0..4] of longint;
	arr1=array[1..2] of real;
var	m,n,i,j:longint;
	zb:array[0..8,1..2] of real;
	p,pp:arr;
function dis(x,y:longint):real;
begin
	dis:=sqr(zb[x,1]-zb[y,1])+sqr(zb[x,2]-zb[y,2]);
end;
function cj(vec1,vec2:arr1):real;
begin
	cj:=vec1[1]*vec2[1]+vec1[2]*vec2[2];
end;
function judge(var p:arr;f:boolean):boolean;
var	i,j,k:longint;
	vec:array[1..4] of arr1;
	flag:boolean;
	len:real;
begin
	for i:=2 to 4 do begin
		vec[i,1]:=zb[p[i],1]-zb[p[1],1];
		vec[i,2]:=zb[p[i],2]-zb[p[1],2];
	end;
	//标记向量
	flag:=false;
	for i:=2 to 3 do begin
		for j:=i+1 to 4 do begin
			if cj(vec[i],vec[j])=0 then begin
				flag:=true;
				break;
			end;
		end;
		if flag then break;
	end;
	if not flag then exit(false);
	//得到与第一个点相垂直的两个向量
	for k:=2 to 4 do 
		if (k<>i) and (k<>j) then break;
	//求得最后一个点
	vec[1,1]:=zb[p[k],1]-zb[p[i],1];
	vec[1,2]:=zb[p[k],2]-zb[p[i],2];
	if cj(vec[i],vec[1])<>0 then exit(false);
	vec[1,1]:=zb[p[k],1]-zb[p[j],1];
	vec[1,2]:=zb[p[k],2]-zb[p[j],2];
	if cj(vec[j],vec[1])<>0 then exit(false);
	//求得3个点垂直
	if not f then exit(true);

	len:=dis(p[i],p[1]);
	if dis(p[j],p[1])<>len then exit(false);
	if (dis(p[j],p[k])<>len) or (dis(p[i],p[k])<>len) then exit(false);
	//判断四条边相等
	exit(true);
end;
procedure print;
var	i:longint;
begin
	writeln('YES');
	for i:=1 to 4 do write(p[i],' ');
	writeln;
	for i:=1 to 4 do write(pp[i],' ');
	writeln;
	halt;
end;
procedure dfs(tot:longint);
var	i,j:longint;
	flag:boolean;
begin
	// if ((p[1]==5)&&(p[2]==6)&&(p[3]==7))
	// if ((p[1]=5)and(p[2]=6))
	if tot>4 then begin
		pp[0]:=0;
		for i:=1 to n do begin
			flag:=false;
			for j:=1 to tot do 
				if p[j]=i then begin
					flag:=true;
					break;
				end;
			if not flag then begin
				inc(pp[0]);
				pp[pp[0]]:=i;
			end;
		end;
		if judge(p,true) and judge(pp,false) then print;
		exit;
	end else begin
		for i:=p[tot-1]+1 to n-4+tot do begin
			p[tot]:=i;
				dfs(tot+1);
			p[tot]:=0;
		end;	
	end;
end;
begin
	assign(input,'1.in');reset(input);
	n:=8;
	for i:=1 to n do 
		read(zb[i][1],zb[i][2]);
	dfs(1);
	writeln('NO');
	//close(input);
end.
