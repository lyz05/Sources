const	maxn=100000+10;lim=1000000+10;limm=1000;
var	n,best,id,i,j,tmp:longint;
	a:array[1..maxn] of longint;
	prime,list,cnt:array[0..limm] of longint;
	min,sub,minid,subid:array[0..lim] of longint;
        flag:array[1..lim] of boolean;
procedure push(x:longint);
begin
	inc(prime[0]);
	prime[prime[0]]:=x;
end;
procedure prepar;
var     i:longint;
begin
	fillchar(flag,sizeof(flag),false);
	for i:=2 to lim-1 do begin
		if not flag[i] then push(i);
		j:=1;
		while (j<=prime[0]) and (i*prime[j]<lim) do begin
			flag[i*prime[j]]:=true;
			if i mod prime[j]=0 then break;	//i的倍数以过滤
			inc(j);
		end;
	end;
end;
procedure factor(x:longint);
var	i:longint;
begin
	fillchar(list,sizeof(list),0);
	fillchar(cnt,sizeof(cnt),0);
	i:=1;
	while (i<=prime[0]) and (sqr(prime[i])<=x) do begin
		if x=1 then break;
		if x mod prime[i]=0 then begin
			inc(list[0]);
			list[list[0]]:=prime[i];
			inc(cnt[0]);
			cnt[cnt[0]]:=0;
			while x mod prime[i]=0 do begin
				x:=x div prime[i];
				inc(cnt[cnt[0]]);
			end;
		end;
		inc(i);
	end;
	if (x>1) then begin
		inc(list[0]);
		list[list[0]]:=x;
                inc(cnt[0]);
		cnt[cnt[0]]:=1;
	end;
end;
procedure update(num,val,curid:longint);
begin
	if (val<min[num]) then begin
		sub[num]:=min[num];
		subid[num]:=minid[num];
		min[num]:=val;
		minid[num]:=curid;
	end else if (val<sub[num]) then begin
		sub[num]:=val;
		subid[num]:=curid;
	end;
end;
procedure dfs(dep,num,rem,id:longint);
begin
	if (dep>list[0]) then begin
		update(num,rem,id);
		exit;
	end;
	if (cnt[dep]<>0) then begin
		dec(cnt[dep]);
		dfs(dep,num*list[dep],rem-1,id);
		inc(cnt[dep]);
	end;
	dfs(dep+1,num,rem,id);
end;

procedure solve(dep,num,rem,curid:longint);
var	tmp,tid,t:longint;
begin
	if dep>list[0] then begin
		if minid[num]=curid then begin
			t:=sub[num];
			tid:=subid[num];
	       	end else begin
			t:=min[num];
			tid:=minid[num];
		end;
		tmp:=rem+t;
		if (tmp<best) or ((tmp=best) and (tid<id)) then begin
			best:=tmp;
			id:=tid;
		end;
                exit;
	end;
	if cnt[dep]<>0 then begin
		dec(cnt[dep]);
		solve(dep,num*list[dep],rem-1,curid);
		inc(cnt[dep]);
	end;
	solve(dep+1,num,rem,curid);
end;
begin
        //assign(input,'data.in');reset(input);
	readln(n);
	prepar;
        fillchar(min,sizeof(min),$3f);
        fillchar(sub,sizeof(sub),$3f);
	for i:=1 to n do begin
                readln(a[i]);
		factor(a[i]);
		tmp:=0;
		for j:=1 to cnt[0] do inc(tmp,cnt[j]);
		dfs(1,1,tmp,i);
	end;
	for i:=1 to n do begin
		factor(a[i]);
		id:=n+1;
		best:=maxlongint;
		tmp:=0;
		for j:=1 to cnt[0] do inc(tmp,cnt[j]);
		solve(1,1,tmp,i);
		writeln(id);
	end;
end.
