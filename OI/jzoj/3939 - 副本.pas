const	maxn=100000;maxai=1000000;maxp=15;
	pri:array[1..maxp] of longint=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47);
var	i,j,k,n,tmp,ans,kk,tkk:longint;
	a:array[0..maxn] of longint;
	min,minid,smin,sminid:array[1..maxai] of longint;
	p:array[0..maxp] of longint;
function fj(x:longint):longint;
var	i:longint;
begin
	fillchar(p,sizeof(p),0);
	fj:=0;
	for i:=1 to maxp do
		while x mod pri[i]=0 do begin
			x:=x div pri[i];
			//if p[p[0]]<>pri[i] then begin
				inc(p[0]);
				p[p[0]]:=pri[i];
			//end;
			inc(fj);
		end;
	if x<>1 then inc(fj);
end;
begin
        //assign(output,'3939.out');rewrite(output);
	readln(n);
	for i:=1 to n do begin
		read(a[i]);

	end;
	fillchar(min,sizeof(min),127);
	fillchar(smin,sizeof(smin),127);
        fillchar(minid,sizeof(minid),127);
        fillchar(sminid,sizeof(sminid),127);
	for i:=1 to n do begin
		for j:=1 to trunc(sqrt(a[i])) do begin
			if a[i] mod j=0 then begin
                                k:=a[i] div j;
				tmp:=fj(k);
				if (tmp>min[j]) and (tmp<smin[j]) then begin
					smin[j]:=tmp;
					sminid[j]:=i;
				end;
				if (tmp<min[j]) or (tmp=min[j]) and (i<minid[j]) then begin
                                        smin[j]:=min[j];
                                        sminid[j]:=minid[j];
                                        min[j]:=tmp;
					minid[j]:=i;
				end;

				tmp:=fj(j);
				if (tmp>min[k]) and (tmp<smin[k]) then begin
					smin[k]:=tmp;
					sminid[k]:=i;
				end;
				if (tmp<min[j]) or (tmp=min[j]) and (i<minid[j]) then begin
                                        smin[k]:=min[k];
                                        sminid[k]:=minid[k];
					min[k]:=tmp;
					minid[k]:=i;
				end;
			end;
		end;
	end;
	for i:=1 to n do begin
		ans:=maxlongint;
                kk:=maxlongint;
		for j:=1 to trunc(sqrt(a[i])) do begin
			if a[i] mod j=0 then begin
				k:=a[i] div j;
				if minid[j]<>i then begin
					tmp:=fj(k)+min[j];
					tkk:=minid[j];
				end else begin
					tmp:=fj(k)+smin[j];
					tkk:=sminid[j];
				end;
				if (tmp<ans) or ((tmp=ans) and (tkk<kk)) then begin
					ans:=tmp;
					kk:=tkk;
				end;

				if minid[k]<>i then begin
					tmp:=fj(j)+min[k];
					tkk:=minid[k];
				end else begin
					tmp:=fj(j)+smin[k];
					tkk:=sminid[k];
				end;
				if (tmp<ans) or ((tmp=ans) and (tkk<kk)) then begin
					ans:=tmp;
					kk:=tkk;
				end;
			end;
		end;
		writeln(kk);
	end;
end.
