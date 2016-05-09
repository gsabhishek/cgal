#ifndef SCENE_SEGMENTED_IMAGE_ITEM_H
#define SCENE_SEGMENTED_IMAGE_ITEM_H

#include <CGAL/Three/Scene_item.h>
#include "Image_type_fwd.h"
#include "Scene_segmented_image_item_config.h"
#include <CGAL/gl.h>

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

#include <CGAL/Three/Scene_interface.h>
#include <CGAL/Three/Viewer_interface.h>

typedef CGAL::Image_3 Image;
using namespace CGAL::Three;

struct Scene_segmented_image_item_priv;
class SCENE_SEGMENTED_IMAGE_ITEM_EXPORT Scene_segmented_image_item 
  : public Scene_item
{
  Q_OBJECT
public:

  Scene_segmented_image_item(Image* im, int drawing_scale);
  ~Scene_segmented_image_item();

  bool isFinite() const { return true; }
  bool isEmpty() const { return false; }
  void compute_bbox() const;

  Scene_segmented_image_item* clone() const { return NULL; }

  // rendering mode
  virtual bool supportsRenderingMode(RenderingMode m) const;

  // draw
  virtual void direct_draw(CGAL::Three::Viewer_interface* viewer) const
  { draw(viewer); }
  virtual void direct_drawEdges(CGAL::Three::Viewer_interface* viewer) const
  { drawEdges(viewer); }
  virtual void draw(CGAL::Three::Viewer_interface*) const;
  virtual void drawEdges(CGAL::Three::Viewer_interface* viewer) const;
  virtual QString toolTip() const;
  const Image* image() const { return m_image; }
  Image* m_image;
protected :
  friend struct Scene_segmented_image_item_priv;
  Scene_segmented_image_item_priv* d;
public Q_SLOTS:
    void changed();
};

#endif // SCENE_SEGMENTED_IMAGE_ITEM_H
