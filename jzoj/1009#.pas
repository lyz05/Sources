const
	maxn=100;
var
	left,right:array[-maxn..maxn]of longint;
	num:array[1..maxn]of longint;
	median,n,position,answer:longint;
procedure scanf;
var
	i:longint;
begin
	//assign(input,'data.in');
       //reset(input);
	readln(n,median);
	for i:=1 to n do
	begin
		read(num[i]);
		if num[i]=median then
			position:=i;
	end;
       //close(input);
end;

procedure solve;
var
	i,temp:longint;
begin
	temp:=0;
	left[0]:=1;
	right[0]:=1;
	for i:=position-1 downto 1 do
	begin
		if num[i]<median then
			inc(temp)
		else
			dec(temp);
		inc(left[temp]);
	end;
	temp:=0;
	for i:=position+1 to n do
	begin
		if num[i]<median then
			inc(temp)
		else
			dec(temp);
		inc(right[temp]);
	end;
	answer:=0;
	for i:=-n to n do
		inc(answer,left[i]*right[-i]);
end;

procedure printf;
begin
      //assign(output,'data.out');
      //rewrite(output);
	writeln(answer);
      //close(output);
end;

begin
	scanf;
	solve;
	printf;
end.
