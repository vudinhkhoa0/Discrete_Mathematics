bool operator > (const node &leftHandSide, const node &rightHandSide)
{
    return leftHandSide.dist < rightHandSide.dist;
}