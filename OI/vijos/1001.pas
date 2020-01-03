const	maxn=100;
type	node=record
		name:string;
		score1,score2,cnt,money:longint;
		flag1,flag2:boolean;
	end;
var	i,j,k,m,n,tot,ans,kk,max:longint;
	inf:array[1..maxn] of node;
	s,ts:string;
begin
	assign(input,'1001.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
	for i:=1 to n do begin
		readln(s);
		s:=s+' ';
		ts:='';tot:=0;
		for j:=1 to length(s) do begin
			if s[j]=' ' then begin
				inc(tot);
				case tot of
					1:inf[i].name:=ts;
					2:val(ts,inf[i].score1);
					3:val(ts,inf[i].score2);
					4:if ts='Y' then
						inf[i].flag1:=true;
					5:if ts='Y' then
						inf[i].flag2:=true;
					6:val(ts,inf[i].cnt);	
				end;	
				ts:='';
				continue;
			end;
			ts:=ts+s[j];
		end;
	end;

	max:=0;ans:=0;
	for i:=1 to n do begin
		if (inf[i].score1>80) and (inf[i].cnt>0) then 
			inc(inf[i].money,8000);
		if (inf[i].score1>85) and (inf[i].score2>80) then
			inc(inf[i].money,4000);
		if (inf[i].score1>90) then 
			inc(inf[i].money,2000);
		if (inf[i].score1>85) and (inf[i].flag2) then
			inc(inf[i].money,1000);
		if (inf[i].score2>80) and (inf[i].flag1) then
			inc(inf[i].money,850);
		inc(ans,inf[i].money);
		if inf[i].money>max then begin
			max:=inf[i].money;
			kk:=i;
		end;
	end;
	writeln(inf[kk].name);
	writeln(max);
	writeln(ans);
end.
