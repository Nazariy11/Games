#include "Tetris.h"
#include<string>

Tetris::Tetris() : m_Figure(Point(5,1))
                    ,m_NextFigure(Point(15,1))
{
    m_square.Resize(14, 26);
    m_Canvas.Resize(26, 20);
}

void Tetris::OnKeyPressed(int btnCode)
{
    switch (btnCode)
    {
    case 32:
        m_Figure.Rotate();
        break;
    case 75:
            m_Figure.MoveL();
            break;
    case 77:
        m_Figure.MoveR();
        break;
    case 80:
        m_Figure.Boost();
        return;
    default:
        break;
    }

    if (m_square.HasColision(m_Figure)) {
        m_Figure.Restore();
     }
}


void Tetris::Update(double dt)
{
    m_Figure.Backup();
    m_Figure.Update(dt);
    if (m_square.HasColision(m_Figure)) {
        m_Figure.Restore();
       m_Score += m_square.Merge(m_Figure);
       if (m_Score > 999999) m_Score = 999999;
        m_Figure = m_NextFigure;
        m_Figure.SetPosition(Point(5, 1));
        m_NextFigure =Figure(Point(15, 1));
        if (m_square.HasColision(m_Figure)) {
            m_End = true;
        }
    }
    m_Canvas.Clear();
    
    m_square.Draw(m_Canvas);

    m_Figure.Draw(m_Canvas);
    m_NextFigure.Draw(m_Canvas);
    DrawScore(m_Canvas);
    m_Canvas.Render();
}

bool Tetris::End()
{
    return m_End;
}

void Tetris::DrawScore(Canvas& canvas)
{
    std::string score = std::to_string(m_Score);
    m_Canvas.SetChar(14, 4, 'S');
    m_Canvas.SetChar(15, 4, 'C');
    m_Canvas.SetChar(16, 4, 'O');
    m_Canvas.SetChar(17, 4, 'R');
    m_Canvas.SetChar(18, 4, 'E');
    m_Canvas.SetChar(19, 4, ':');

    m_Canvas.SetChar(14, 7, 'L');
    m_Canvas.SetChar(15, 7, 'E');
    m_Canvas.SetChar(16, 7, 'F');
    m_Canvas.SetChar(17, 7, 'T');
    m_Canvas.SetChar(18, 7, ':');
    m_Canvas.SetChar(14, 8, 'b');
    m_Canvas.SetChar(15, 8, 't');
    m_Canvas.SetChar(16, 8, 'n');
    m_Canvas.SetChar(17, 8, '.');
    m_Canvas.SetChar(18, 8, 'L');

    m_Canvas.SetChar(14, 10, 'R');
    m_Canvas.SetChar(15, 10, 'I');
    m_Canvas.SetChar(16, 10, 'G');
    m_Canvas.SetChar(17, 10, 'H');
    m_Canvas.SetChar(18, 10, 'T');
    m_Canvas.SetChar(18, 10, ':');
    m_Canvas.SetChar(14, 11, 'b');
    m_Canvas.SetChar(15, 11, 't');
    m_Canvas.SetChar(16, 11, 'n');
    m_Canvas.SetChar(17, 11, '.');
    m_Canvas.SetChar(18, 11, 'R');

    m_Canvas.SetChar(14, 13, 'D');
    m_Canvas.SetChar(15, 13, 'O');
    m_Canvas.SetChar(16, 13, 'W');
    m_Canvas.SetChar(17, 13, 'N');
    m_Canvas.SetChar(18, 13, ':');
    m_Canvas.SetChar(14, 14, 'b');
    m_Canvas.SetChar(15, 14, 't');
    m_Canvas.SetChar(16, 14, 'n');
    m_Canvas.SetChar(17, 14, '.');
    m_Canvas.SetChar(18, 14, 'D');

    m_Canvas.SetChar(14, 16, 'T');
    m_Canvas.SetChar(15, 16, 'U');
    m_Canvas.SetChar(16, 16, 'R');
    m_Canvas.SetChar(17, 16, 'N');
    m_Canvas.SetChar(18, 16, ':');
    m_Canvas.SetChar(14, 17, 'S');
    m_Canvas.SetChar(15, 17, 'P');
    m_Canvas.SetChar(16, 17, 'A');
    m_Canvas.SetChar(17, 17, 'C');
    m_Canvas.SetChar(18, 17, 'E');

    
    for (size_t i = 0; i < score.size(); i++)
    {
        m_Canvas.SetChar(14 + i, 5, score[i]);
    }
}
