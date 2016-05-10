procedure DP_1 (u , fa : longint) ;
var	p : longint ;
begin
	p := vr ; size := stu ;
	while (p <> -1) do begin
		if (arc[p].d <> fa) then begin
			DP_1 (arc[p].d , u) ;
			inc (size , size[arc[p].d]) ;
			inc (sum , sum[arc[p].d] + arc[p].w * size[arc[p].d]) ;
		end ;
		p := arc[p].next ;
	end;
end ;

procedure DP_2 (u , fa : longint) ;
var	p : longint ;
begin
	if (f < ans) then begin
		loc := u ;
		ans := f ;
	end ;
	p := vr ;
	while (p <> -1) do begin
		if (arc[p].d <> fa) then begin
			f[arc[p].d] := f + arc[p].w * (size[1] - size[arc[p].d] * 2) ;
			DP_2 (arc[p].d , u) ;
		end ;
		p := arc[p].next ;
	end ;
end ; 

