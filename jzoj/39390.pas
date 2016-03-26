type
	List=^PointType;
	PointType=
	record
		Data,Diff:longint;
		Next:List;
	end;
const
	Maxn=100000;
	Maxa=1000000;
	Maxp=trunc(ln(Maxa)/ln(2))+1;
	Maxl=trunc(sqrt(Maxa))+1;
var
	Fir,FirID,Sec,SecID:array[1..Maxa]of longint;
	Factor,Tail:array[1..Maxn]of List;
	Pfa:array[1..Maxp,0..1]of longint;
	Num,Answer,Value:array[1..Maxn]of longint;
	Check:array[1..Maxl]of boolean;
	Prime:array[0..Maxl]of longint;
	n,Maxnum,Lim,Sum,Count:longint;
procedure Insert(Pos,Number,Step:longint);
var
	p:List;
begin
	new(p);
	p^.Data:=Number;
	p^.Diff:=Step;
	inc(Factor[Pos]^.Data);
	Tail[Pos]^.Next:=p;
	Tail[Pos]:=p;
end;

procedure Decompose(x,Last:longint);
var
	i:longint;
begin
	if x=1 then
		exit;
	for i:=Last to Prime[0] do
		if x mod Prime[i]=0 then
		begin
			inc(Sum);
			Pfa[Sum,0]:=Prime[i];
			while x mod Prime[i]=0 do
			begin
				inc(Pfa[Sum,1]);
				x:=x div Prime[i];
			end;
			inc(Count,Pfa[Sum,1]);
			Decompose(x,i+1);
			exit;
		end;
	inc(Sum);
	Pfa[Sum,0]:=x;
	Pfa[Sum,1]:=1;
	inc(Count);
end;

procedure Dfs(Now,Pri,Pos,Used:longint);
var
	i:longint;
begin
	if Pri=Sum+1 then
	begin
		Insert(Pos,Now,Count-Used);
		if (Fir[Now]>Count-Used) or (Fir[Now]=Count-Used) and (FirID[Now]>Pos) then
		begin
                        Sec[Now]:=Fir[Now];
                        SecID[Now]:=FirID[Now];
			Fir[Now]:=Count-Used;
			FirID[Now]:=Pos;
		end
		else
			if (Sec[Now]>Count-Used) or (Sec[Now]=Count-Used) and (SecID[Now]>Pos) then
			begin
				Sec[Now]:=Count-Used;
				SecID[Now]:=Pos;
			end;
		exit;
	end;
        Dfs(Now,Pri+1,Pos,Used);
	for i:=1 to Pfa[Pri,1] do
	begin
		Now:=Now*Pfa[Pri,0];
		inc(Used);
		Dfs(Now,Pri+1,Pos,Used);
	end;
end;

procedure Preparation;
var
	i,j:longint;
begin
	fillchar(Check,sizeof(Check),1);
	Check[1]:=false;
	for i:=2 to trunc(sqrt(Lim)) do
		if Check[i] then
			for j:=i to Lim div i do
				Check[i*j]:=false;
	for i:=1 to Lim do
		if Check[i] then
		begin
			inc(Prime[0]);
			Prime[Prime[0]]:=i;
		end;
	for i:=1 to Maxnum do
	begin
		Fir[i]:=Maxlongint>>1;
		FirID[i]:=n+1;
		Sec[i]:=Maxlongint>>1;
		SecID[i]:=n+1;
	end;
	for i:=1 to n do
	begin
		Sum:=0;
                Count:=0;
		fillchar(Pfa,sizeof(Pfa),0);
		Decompose(Num[i],1);
		new(Factor[i]);
		Factor[i]^.Data:=0;
		Tail[i]:=Factor[i];
		Dfs(1,1,i,0);
	end;
end;

procedure Scanf;
var
	i:longint;
begin
	assign(input,'data.in');
	reset(input);
	readln(n);
	for i:=1 to n do
	begin
		readln(Num[i]);
		if Num[i]>Maxnum then
			Maxnum:=Num[i];
	end;
	Lim:=trunc(sqrt(Maxnum))+1;
	close(input);
end;

procedure Solve;
var
	i,j:longint;
	p:List;
begin
	Preparation;
	for i:=1 to n do
	begin
		Answer[i]:=n+1;
		Value[i]:=Maxlongint>>1;
		p:=Factor[i];
		for j:=1 to Factor[i]^.Data do
		begin
			p:=p^.Next;
			if FirID[p^.Data]=i then
			begin
				if (Sec[p^.Data]+p^.Diff<Value[i]) or (Sec[p^.Data]+p^.Diff=Value[i]) and (SecID[p^.Data]<Answer[i]) then
				begin
					Answer[i]:=SecID[p^.Data];
                                        Value[i]:=Sec[p^.Data]+p^.Diff;
				end;
			end
			else
				if (Fir[p^.Data]+p^.Diff<Value[i]) or (Fir[p^.Data]+p^.Diff=Value[i]) and (FirID[p^.Data]<Answer[i]) then
				begin
					Answer[i]:=FirID[p^.Data];
					Value[i]:=Fir[p^.Data]+p^.Diff;
				end;
		end;
	end;
end;

procedure Printf;
var
	i:longint;
begin
	assign(output,'data.out');
	rewrite(output);
	for i:=1 to n do
		writeln(Answer[i]);
	close(output);
end;

begin
	Scanf;
	Solve;
	Printf;
end.
