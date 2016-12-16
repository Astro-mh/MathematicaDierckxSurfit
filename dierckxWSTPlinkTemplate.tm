:Begin:
:Function:       surfit
:Pattern:        surfit[iopt_Integer,m_Integer,x_List,y_List,z_List,w_List,xb_Real,xe_Real,yb_Real,ye_Real,kx_Integer,ky_Integer,s_Real,nxest_Integer,nyest_Integer,nmax_Integer,eps_Real,nx_Integer,tx_List,ny_Integer,ty_List]
:Arguments:      {iopt,m,x,y,z,w,xb,xe,yb,ye,kx,ky,s,nxest,nyest,nmax,eps,nx,tx,ny,ty}
:ArgumentTypes:  {Integer,Integer,Manual}
:ReturnType:     Manual
:End:

:Begin:
:Function:       bispev
:Pattern:        bispev[tx_List,ty_List,c_List,kx_Integer,ky_Integer,x_List,y_List]
:Arguments:      {tx,ty,c,kx,ky,x,y}
:ArgumentTypes:  {Manual}
:ReturnType:     Manual
:End:

:Begin:
:Function:       bispevSA
:Pattern:        bispevSA[tx_List,ty_List,c_List,kx_Integer,ky_Integer,x_List,y_List,yorig_List]
:Arguments:      {tx,ty,c,kx,ky,x,y,yorig}
:ArgumentTypes:  {Manual}
:ReturnType:     Manual
:End:
