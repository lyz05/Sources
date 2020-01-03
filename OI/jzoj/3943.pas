uses math;
const	maxn=1000007;
var	f:array[1..maxn] of longint;
	g:array[1..maxn*2] of longint;
	d:array[1..maxn] of longint;
	bz,bz2:array[1..maxn] of longint;
	i,ii,j,m,n,tot,minf,t,x,dis,l,r,ll,rr,sum,y,last,now:longint;
        ans:int64;
begin
	readln(n,t);
	for i:=1 to n do begin
		read(g[i]);
		sum:=sum+g[i];
		minf:=max(g[i],minf);
	end;
	for i:=n+1 to 2*n do g[i]:=g[i-n];

	d[1]:=0;
	for i:=2 to n do d[i]:=d[i-1]+g[i-1];
	fillchar(g,sizeof(g),0);

	for i:=1 to t do begin
		read(x);
		if sum<=x then begin
			writeln(1);
			continue;
		end;
		if minf>x then begin
			writeln('NO');
                        continue;
		end;
		l:=1;r:=1;
		while l<=n do begin
			while (l<=r) do begin
				if (r>n) then begin
					ll:=r-n;
					rr:=l;
					dis:=sum-(d[rr]-d[ll]);
				end else begin
					ll:=l;rr:=r;
					dis:=d[rr]-d[ll];
				end;
				if (dis<=x) then break;
				g[l]:=r-1;
				inc(l);
			end;
			inc(r);
		end;
		for ii:=n+1 to 2*N do g[ii]:=g[ii-n]+n;
		fillchar(bz,sizeof(bz),0);
		ans:=n+1;
		tot:=0;
		for ii:=1 to n do begin
			if bz[ii]=0 then begin
				l:=1;r:=1;
				bz[ii]:=0;f[1]:=ii;
				t:=0;y:=g[ii];
				while (l<=r) do begin
					if f[l]>n then break;
					if y<=n then begin
						inc(r);
						f[r]:=y;
					end;
					if (y<=n) and (bz[y]<>0) then break;
					while (y-n>=f[l]) and (l<=r) do begin
						bz[f[l]]:=t+1-l+1;
						bz2[f[l]]:=(last-1) mod n+1;
						ans:=min(ans,t+1-l+1);
						inc(l);
					end;
					last:=y;
					y:=g[y];
					inc(t);
				end;
				if (l<=r) then begin
					for y:=r-1 downto l do begin
						now:=bz2[f[y+1]];
						t:=bz[f[y+1]];
						if (now<=f[y]) then begin
							bz[f[y]]:=t;
							bz2[f[y]]:=now
						end else begin
							now:=bz2[now];
							bz[f[y]]:=t;
							bz2[f[y]]:=now;
						end;
						ans:=min(ans,t);
					end;
				end;
			end;
		end;
		writeln(ans);
	end;
end.
