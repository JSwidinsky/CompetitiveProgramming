set expandtab

" Be smart when using tabs ;)
set smarttab

" 1 tab == 4 spaces
set shiftwidth=2
set tabstop=2

" Linebreak on 500 characters
set lbr
set tw=500

set ai "Auto indent
set si "Smart indent
set number

map <F4> :! pdflatex %<CR>
:noremap <C-I> :tabnew ~/Documents/contest/input.in <CR>
:noremap <F10> :! ~/Documents/contest/run.sh % <CR>
map <F5> :tabnew ~/Documents/codelibrary/ICPC/algorithms/book <CR>
map <leader>tp :r ~/Documents/contest/template.cpp<CR>ggdd
