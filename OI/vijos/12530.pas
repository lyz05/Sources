var
	dest,c,dy,pay,cy:real; {输入的第一行信息}
	dis,p:array[-1..100] of real; {dis[i],p[i]描述第i个加油站的信息}
	ans,t,d,min:real;
	i,j,k,l,m,n:longint;
procedure init;
begin
	readln(dest,c,dy,pay,n);
	for i:=1 to n do readln(dis[i],p[i]);
	p[0]:=pay;
end;

begin
	assign(input,'1253.in');reset(input);
	init;
	d:=0; {旅行家的位置}
	cy:=0; {库存油量}
	ans:=0; {花费}
	i:=0;
	while d<dest do
	begin
		min:=maxlongint;
		if (i=n) and (d+c*dy>=dest) then
		{如果旅行家已经去到最后一个加油,那直接去到终点}
		begin
			ans:=ans+(dest-dis[i]-cy*dy)/dy*p[i];
			d:=dest;
			break;
		end;
		j:=i+1;
		if (d+dy*c<dis[j]) then break;
		{如果不能去到下一个加油站就输出-1}
		while (d+dy*c>=dis[j]) and (j<=n) do
		begin
		{在能够去到下一个加油站的情况下,比较去哪个加油站最好}
			if (p[j]-p[i]<min) then
			begin
				min:=p[j]-p[i];
				k:=j;
			end;
			inc(j);
		end;
		
		if (dy*c+d>=dest) then
		begin {是否能直接去到终点}
			if (p[i]<p[k]) then {比较是否去下一个加油站或直接到终点更好}
			begin
				ans:=ans+(dest-dis[i]-cy*dy)/dy*p[i];
				d:=dest;
				break;
			end else
				if (p[i]>=p[k]) then
				begin
					ans:=ans+(dis[k]-dis[i]-cy*dy)/dy*p[i];
					cy:=0;
					d:=dis[k];
					i:=k;
				end;
		end else
		begin
			if (p[i]<p[k]) then
			{如果不能直接去到终点那比较到哪个加油站好}
			begin
				ans:=ans+c*p[i];
				cy:=c-(dis[k]-d)/dy;
				{加满油}
				d:=dis[k];
				i:=k;
			end else
				if (p[i]>=p[k]) then
				begin
					ans:=ans+(dis[k]-d-cy*dy)/dy*p[i];
					{只需加能够去到下一个加油站的油量}
					cy:=0;
					d:=dis[k];
					i:=k;
				end;
		end;
	end;
	if d=dest then writeln(ans:0:2) else writeln(-1);
end.
